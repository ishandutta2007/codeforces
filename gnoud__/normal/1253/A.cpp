#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
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
int n,a[100005],b[100005];
main()
{
    int test; cin>>test; while(test--)
    {
        cin>>n;
        forinc(i,1,n) cin>>a[i];
        forinc(i,1,n) cin>>b[i];
        int khac=0,lech;
        forinc(i,1,n)
        {
            if(a[i]!=b[i])
            {
                khac=1;
                lech=b[i]-a[i];
            }
        }
        if(!khac)
        {
            cout<<"YES\n";
            continue;
        }
        if(lech<0)
        {
            cout<<"NO\n";
            continue;
        }
        int thaydoi=0;
        forinc(i,1,n){
            if(a[i]+lech==b[i]){
                a[i]+=lech;
                thaydoi=1;
                continue;
            }
            if(thaydoi && a[i]+lech!=b[i]){
                break;
            }
        }
        khac=0;
        forinc(i,1,n) if(a[i]!=b[i]) khac=1;
        cout<<(khac?"NO\n":"YES\n");
    }
}