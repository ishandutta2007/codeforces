#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
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

int main(){
    int n;
    string s;
    vector<int> a;
    vector<vector<int>> ans;
    cin>>s; n=s.size();
    forinc(i,1,s.size())
        a.pb(s[i-1]=='(' ? 1 : 0);
    while(1){
        int l=0, r=a.size()-1;
        vector<int> pf,sf;
        while(l<=r){
            while(l<a.size() && !a[l]) l++;
            while(r>=0 && a[r]) r--;
            if(l>=r) break;
            if(l<a.size()) pf.pb(l);
            if(r>=0) sf.pb(r);
            l++, r--;
        }
        int sz=min(pf.size(),sf.size());
        if(!sz) break;
        vector<int> nxt;
        forinc(i,0,sz-1) nxt.pb(pf[i]);
        fordec(i,(int)sf.size()-1,(int)sf.size()-sz) nxt.pb(sf[i]);
        ans.pb(nxt);
        reverse(all(nxt));
        forv(i,nxt) a.erase(a.begin()+i);
    }
    cout<<ans.size()<<"\n";
    forv(i,ans){
        cout<<i.size()<<"\n";
        forv(j,i) cout<<j+1<<" "; cout<<"\n";
    }
}