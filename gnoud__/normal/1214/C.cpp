#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
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
const int N=1e6;
int n,a[N],s[N],mx[N][20];
int get(int i,int j)
{
    int tg=log2(j-i+1);
    return min(mx[i][tg],mx[j-(1<<tg)+1][tg]);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    cin>>n;
    forinc(i,1,n)
    {
        char c;
        cin>>c;
        a[i]=(c=='(')?1:-1;
        s[i]=s[i-1]+a[i];
        mx[i][0]=s[i];
    }
    if(s[n]!=0) return cout<<"No",0;
    forinc(j,1,log2(n))
    forinc(i,1,n) mx[i][j]=min(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    forinc(i,1,n)
    {
        int j=i;
        if(a[i]==1)
        {
            if(get(1,i-1)+(j-i+1)>=0&&get(j+1,n)-s[j]+s[i-1]+(j-i+1)>=0) return cout<<"Yes",0;
        }
        else
        {
            if(get(1,i-1)>=0&&get(j+1,n)-s[j]+s[i-1]>=0) return cout<<"Yes",0;
        }
    }
    cout<<"No";
}