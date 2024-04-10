#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=5001;
int n,k;
ll t[N],p[N];
bool c1[N],c2[N];
ll mn1[N],mx1[N];
ll mn2[N],mx2[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> t[i] >> p[i];
		mn1[i]=mn2[i]=1e18;
		mx1[i]=mx2[i]=-1e18;
	}
	c1[0]=true;
	for(int i=0; i<n ;i++){
		/*cout << "doing " << i << endl;
		cout << c1[i] << ' ' << c2[i] << endl;
		cout << mn1[i] << ' ' << mx1[i] << endl;
		cout << mn2[i] << ' ' << mx2[i] << endl;*/
		if(c1[i]){
			ll cmn,cmx;
			for(int j=i+1; j<=n ;j++){
				if(j==i+1){
					ll d=max(p[j]-mx1[i],mn1[i]-p[j]);
					d=max(d,0LL);
					d=t[j]-t[i]-d;
					if(d<0) break;
					c1[j]=true;
					mx1[j]=max(mx1[j],p[j]+d);
					mn1[j]=min(mn1[j],p[j]-d);
					cmx=min(mx1[i],p[j]+t[j]-t[i]);
					cmn=max(mn1[i],p[j]-t[j]+t[i]);
					ll tmp=t[j]-t[i]-p[j]+cmn;
					if(tmp>0) cmn-=tmp/2;
					tmp=t[j]-t[i]+p[j]-cmx;
					if(tmp>0) cmx+=tmp/2;
				}
				else{
					if(cmn<=p[j] && p[j]<=cmx){
						c2[j]=true;
						mn2[j]=min(mn2[j],p[j-1]+t[j-1]-t[j]);
						mx2[j]=max(mx2[j],p[j-1]-t[j-1]+t[j]);
					}
					if(abs(p[j]-p[j-1])>t[j]-t[j-1]) break;
					c1[j]=true;
					mn1[j]=min(mn1[j],p[j]);
					mx1[j]=max(mx1[j],p[j]);
					ll tmp=t[j]-t[j-1]-p[j]+p[j-1];
					if(tmp>0) cmn=min(cmn,p[j-1]-tmp/2);
					tmp=t[j]-t[j-1]+p[j]-p[j-1];
					if(tmp>0) cmx=max(cmx,p[j-1]+tmp/2);
				}
			}
		}
		swap(c1[i],c2[i]);
		swap(mx1[i],mx2[i]);
		swap(mn1[i],mn2[i]);
		if(c1[i]){
			ll cmn,cmx;
			for(int j=i+1; j<=n ;j++){
				if(j==i+1){
					ll d=max(p[j]-mx1[i],mn1[i]-p[j]);
					d=max(d,0LL);
					d=t[j]-t[i]-d;
					if(d<0) break;
					c1[j]=true;
					mx1[j]=max(mx1[j],p[j]+d);
					mn1[j]=min(mn1[j],p[j]-d);
					cmx=min(mx1[i],p[j]+t[j]-t[i]);
					cmn=max(mn1[i],p[j]-t[j]+t[i]);
					ll tmp=t[j]-t[i]-p[j]+cmn;
					if(tmp>0) cmn-=tmp/2;
					tmp=t[j]-t[i]+p[j]-cmx;
					if(tmp>0) cmx+=tmp/2;
				}
				else{
					if(cmn<=p[j] && p[j]<=cmx){
						c2[j]=true;
						mn2[j]=min(mn2[j],p[j-1]+t[j-1]-t[j]);
						mx2[j]=max(mx2[j],p[j-1]-t[j-1]+t[j]);
					}
					if(abs(p[j]-p[j-1])>t[j]-t[j-1]) break;
					c1[j]=true;
					mn1[j]=min(mn1[j],p[j]);
					mx1[j]=max(mx1[j],p[j]);
					ll tmp=t[j]-t[j-1]-p[j]+p[j-1];
					if(tmp>0) cmn=min(cmn,p[j-1]-tmp/2);
					tmp=t[j]-t[j-1]+p[j]-p[j-1];
					if(tmp>0) cmx=max(cmx,p[j-1]+tmp/2);
				}
			}
		}
	}
	if(c1[n] || c2[n]) cout << "YES\n";
	else cout << "NO\n";
}