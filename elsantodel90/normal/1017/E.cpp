#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

typedef tint tipo;

typedef long double tdbl;

tdbl EPS = 1e-11;

#define sqr(x) ((x)*(x))


    struct pto {
      tipo x,y;
      tipo n2(pto &p2)const{
        return sqr(x-p2.x)+sqr(y-p2.y);
      }
      pto operator -(const pto &o) const
      {
          return {x-o.x, y-o.y};
      }
      tint operator ^(const pto &o) const
      {
          return x * o.y - y * o.x;
      }
      tint operator *(const pto &o) const
        {
          return x * o.x + y * o.y;  
        }
      
      tint norma2() const { return x*x + y*y;}
      tdbl norma() const { return hypot(x,y);}
      
    } r;


    tipo pcruz(tipo x1,tipo y1,tipo x2,tipo y2){return x1*y2-x2*y1;}
    tipo area3(pto a, pto b, pto c){
      return pcruz(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
    }
    bool men2(const pto &p1, const pto &p2){
      return (p1.y==p2.y)?(p1.x<p2.x):(p1.y<p2.y);
    }
    bool operator<(const pto &p1,const pto &p2){
      tipo ar = area3(r,p1,p2);
      return(ar==0)?(p1.n2(r)<p2.n2(r)):ar>0;
      //< clockwise, >counterclockwise
    }
    typedef vector<pto> VP;
    VP chull(VP & l){
      VP res = l;  if(l.size()<3) return res;
      r = *(min_element(res.begin(),res.end(),men2));
      sort(res.begin(),res.end());
      tint i=0;VP ch;ch.push_back(res[i++]);ch.push_back(res[i++]);
      while(i<int(res.size()))  // area3 > clockwise, < counterclockwise
        if(ch.size()>1 && area3(ch[ch.size()-2],ch[ch.size()-1],res[i])<=0)
          ch.pop_back();
        else
          ch.push_back(res[i++]);
      return ch;
    }

typedef pair<tdbl, tdbl> Par;

bool igual(const Par &a, const Par &b)
{
    return abs(a.first - b.first) < EPS &&
           abs(a.second - b.second) < EPS;
}

bool menor(const Par &a, const Par &b)
{
    return a < b && !igual(a,b);
}

int duval(const vector<Par> &s) {   
    int i = 0, n = int(s.size()), j, k;
    int lastI = -1;
    while (i < n) {
        j = i + 1, k = i;
        while (j < n and (menor(s[k],s[j]) || igual(s[k], s[j]))) {
            if(menor(s[k] , s[j])) k = i; else k++; j++; }
        while (i <= k) {
            if (i < int(s.size())/2)
                lastI = i;
            else
                return lastI;
            
            i += j - k;
        }
    }
    assert(false);
}

Par getPar(pto v1, pto v2, pto v3)
{
    pto a = v1-v2;
    pto b = v3-v2;
    return {tdbl(a*b) / (a.norma() * b.norma()), (v2-v3).norma()};
}

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("e.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    int tam[2] = {N,M};
    VP v[2];
    forn(k,2)
    {
        v[k].resize(tam[k]);
        forn(i, tam[k])
            cin >> v[k][i].x >> v[k][i].y;
        v[k] = chull(v[k]);
    }
    bool ret;
    if (v[0].size() != v[1].size())
        ret = false;
    else
    {
        const int TAM = int(v[0].size());
        if (TAM == 2)
            ret = (v[0][0] - v[0][1]).norma2() == (v[1][0] - v[1][1]).norma2();
        else
        {
            vector<Par> vp[2];
            forn(k,2)
            {
                vp[k].resize(TAM);
                forn(i, TAM)
                    vp[k][i] = getPar(v[k][i], v[k][(i+1)%TAM], v[k][(i+2)%TAM]);
                forn(i, TAM)
                    vp[k].push_back(vp[k][i]);
            }
            int base[2];
            
            forn(k,2) base[k] = duval(vp[k]);
            ret = true;
            forn(i,TAM)
                ret &= igual(vp[0][base[0] + i], vp[1][base[1] + i]);
        }
    }
    cout << (const char*[]){"NO","YES"}[ret] << endl;
    return 0;
}