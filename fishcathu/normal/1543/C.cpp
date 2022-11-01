#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=2E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
const double eps=1E-9;
double p;
double f(double a,double b,double c)
{
    if(a<eps)a=0;
    if(b<eps)b=0;
    double res=1;
    if(a)
    {
        double d=min(a,p);
        if(b)res+=a*f(a-d,b+d/2,c+d/2);
        else res+=a*f(a-d,b,c+d);
    }
    if(b)
    {
        double d=min(b,p);
        if(a)res+=b*f(a+d/2,b-d,c+d/2);
        else res+=b*f(a,b-d,c+d);
    }
    return res;
}
int main()
{
    for(int x=read();x--;)
    {
        double a,b,c;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&p);
        printf("%.6f\n",f(a,b,c));
    }
}