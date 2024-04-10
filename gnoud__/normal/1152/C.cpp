#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define int long long
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
int kq=2e18,o;
int lcm(int a,int b)
{
    return a*b/ll(__gcd(a,b));
}
void Sol(int a,int b,int x)
{
    if(a%x!=b%x) return;
    int T=(x-a%x)%x;
    int LCM=lcm(a+T,b+T);
    if(LCM<kq) kq=LCM,o=T;
    else if(LCM==kq) o=min(o,T);
}
main()
{
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    int S=b-a;
    kq=lcm(a,b);
    forinc(i,1,sqrt(S)) if(S%i==0) Sol(a,b,i),Sol(a,b,S/i);
    cout<<o;
}