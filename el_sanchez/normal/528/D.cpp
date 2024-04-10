#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
//#include <cmath>
#include <ctime>
#include <assert.h>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);                                
//ll modulo = 786433;
//ll g = 10;
const int P = 19;
const int n = 1 << P;
//typedef complex<double> cd;

struct cd
{
   double a,b;
   cd () {}
   cd (double a, double b):a(a), b(b) {}      
   double real()
   {
      return a;
   }
};

inline cd operator *(const cd &a, const cd &b)
{
    return cd(a.a * b.a - a.b * b.b,  a.b * b.a + a.a * b.b);
}

inline cd operator +(const cd &a, const cd &b)
{
    return cd(a.a + b.a, b.b + a.b);
}

inline cd operator -(const cd &a, const cd &b)
{
    return cd(a.a - b.a, a.b - b.b);
}

inline cd operator /(const cd &a, const double &b)
{
    return cd(a.a / b, a.b / b);
}



const double eps = 0.5;
cd p1[n + 1], p[n + 1], p2[n+1], p3[n+1],  w[n + 1], w1[n + 1];
bool able[n + 1];
int breverse[n + 1], subrev[n+1];  

void calc_brev()
{
   int p2 = (P>>1);
   for (int i = 0; i < (1<<p2); i++)
   {   
      subrev[i] = 0;
      for (int j = 0; j < p2; j++)
         if (i & (1 << j)) subrev[i] |= 1 << (p2 - 1 - j);
   }
   for (int i = 0; i < n; i++)
   {
      breverse[i] = subrev[i>>(p2+(P&1))] | (subrev[i&((1<<p2)-1)] << (p2 + (P&1)));
      if (P&1) breverse[i] |= i & (1 << p2);
      
   } 
}

void calc_w()
{
   w[0] = cd(1., 0.);
   w[1] = cd(cos(2*acos(-1.)/n), sin(2*acos(-1.)/n));
   for (int i = 2; i < n; i++) w[i] = w[i-1] * w[1];
   w1[0] = w[0];
   w1[1] = cd(cos(2*acos(-1.)/n), -sin(2*acos(-1.)/n));
   for (int i = 2; i < n; i++) w1[i] = w1[i-1] * w1[1];
}

void fft(cd* res, cd* p, cd* w)
{
        for (int i = 0; i < n; i++) res[i] = p[breverse[i]];
        cd u, v;
     //   cd* r1, *r2;
        int q;
        for (int len = 1; 2*len <= n; len <<= 1)
        {
           q = n / len / 2;
        //   r1 = res;
        //   r2 = res + len;      
               
           for (int j = 0; j < n; j += (len << 1))
           {
               for (int i = 0; i < len; i++)
               {
                    u = res[j+i]; v = res[j+len+i] * w[i * (q)];
                    res[j+i] = u + v;      
                    res[j+len+i] = u - v;
                  //  r1++; r2++;  
               }
           }
        }    
}
    
string s,t;

const char let[4] = {'A','T','G','C'};

const int C0 = (int)2e5+123;
int prv[C0][4], nxt[C0][4];
bool ok[C0][4];

bool poss[C0*2];

int main()
{
   calc_brev();
   calc_w();
   int N, M, K;
   cin >> N >> M >> K;
   cin >> s >> t;

   assert((int)s.size() == N);
   assert((int)t.size() == M);
   for (int i = 0; i < 4; i++) 
      prv[0][i] = (s[0]==let[i]?0:-(int)1e9);
   for (int i = 1; i < N; i++)    
      for (int j = 0; j < 4; j++) prv[i][j] = (s[i]==let[j]?i:prv[i-1][j]);
       
   for (int i = 0; i < 4; i++) 
      nxt[N-1][i] = (s[N-1]==let[i]?N-1:(int)1e9);
   for (int i = N-2; i >=0; i--)    
      for (int j = 0; j < 4; j++) nxt[i][j] = (s[i]==let[j]?i:nxt[i+1][j]);
   for (int i = 0; i < N; i++)
      for (int j = 0; j < 4; j++)
         ok[i][j] = (i-prv[i][j]<=K)||(nxt[i][j]-i<=K);
   for (int i = M; i < N+M; i++) poss[i] = 1;
   for (int ii = 0; ii < 4; ii++)
   {
      for (int i = 0; i < n; i++)
         p[i] = p2[i] = cd(0.,0.);
      for (int i = 0; i < N; i++) 
         if (!ok[i][ii]) p[i] = cd(1.,0.);
      for (int i = 0; i < M; i++)
         if (t[i] == let[ii]) p2[M-i] = cd(1.,0.);
      fft(p1, p, w);
      fft(p3, p2, w);

      for (int i = 0; i < n; i++) p1[i] = (p1[i] * p3[i]);
      fft(p, p1, w1);
      for (int i = 0; i < n; i++) p[i] = p[i] / (double)n;
      for (int i = M; i < N+M; i++) if (p[i].real() > eps) poss[i] = 0;
   //   for (int i = M; i <= N; i++) cout << poss[i];
   //   cout << endl;
   }
   int cnt = 0;
   for (int i = M; i <= N; i++) if (poss[i]) cnt++;
   cout << cnt << endl;
   return 0;
}