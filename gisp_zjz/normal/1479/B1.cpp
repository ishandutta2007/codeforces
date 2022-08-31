#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+100;
const int M=998244353;
int a[maxn],n,ans;
vector<int> p;
vector<pi> b;
int main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++){
        if (a[i]==a[i-1]) continue;
        if (a[i]==a[i+1]) b.pb((pi){2,a[i]}); else b.pb((pi){1,a[i]});
	}
    for (int i=0;i<(int)b.size();i++){
		pi x=b[i];
		ans+=x.F;
		if (x.F==2) p.pb(i);
    }
    for (int i=0;i<(int)p.size()-1;i++){
        int u=p[i],v=p[i+1];
        if (b[u].S!=b[v].S) continue;
        if ((u-v)&1) continue;
        bool flag=1;
        for (int j=u+2;j<=v-2;j+=2) flag&=b[j].S==b[u].S;
        //for (int j=u+3;j<=v-1;j+=2) flag&=b[j].S==b[u+1].S;
        ans-=flag;
    }
    cout << ans << endl;
    return 0;
}