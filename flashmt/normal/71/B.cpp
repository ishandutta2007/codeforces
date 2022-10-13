#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#define fr(a,b,c) for(a=b;a<=c;a++)
#define frr(a,b,c) for(a=b;a>=c;a--)
#define rp(a,b,c) for(a=b;a<c;a++)
#define rpp(a,b,c) for(a=b;a>c;a--)
#define maxn 100010
using namespace std;
typedef long long ll;

int n,k,t;

int main()
{
    int i;
    cin >> n >> k >> t;
    double tt=1.0*t*n*k/100;
    t=int(tt);
    if (t>tt) t--;
    int x=t/k,y=t%k;
    fr(i,1,x) cout << k << " ";
    if (y>0)
    {
       cout << y << " ";
       fr(i,x+2,n) cout << 0 << " ";
    }
    else
    {
       fr(i,x+1,n) cout << 0 << " "; 
    }
    cout << endl;
    //system("pause");
    return 0;
}