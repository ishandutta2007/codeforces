#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,m,g[505][505],u[505],st,ans=0,x;
pr f[505][505],a[500005];
set<int> s[2];
void Ask(vector<int> v){
	memset(u,0,sizeof(u));
	for(int i:v)u[i]=1;
	int cnt=0; 
	vector<int> vv;
	for(int i=1;i<=n;i++){
		if(u[i])continue;
		vv.push_back(i),cnt++;
		if(cnt==m-v.size()/2)break;
	}
	cout<<"? ";
	for(int i:vv)cout<<i<<' ';
	for(int i=0;i<v.size()/2;i++)cout<<v[i]<<' ';
	cout<<endl,cin>>x,ans^=x;
	cout<<"? ";
	for(int i:vv)cout<<i<<' ';
	for(int i=v.size()/2;i<v.size();i++)cout<<v[i]<<' ';
	cout<<endl,cin>>x,ans^=x;
}
int main(){
	cin>>n>>m;
	memset(g,0x3f,sizeof(g)),g[m][0]=1,f[m][0]=mp(0,0);
	for(int i=m;i<=n;i++){
		for(int j=i;j>=0;j--){
			for(int k=1;i+k<=n&&k<=m;k++){
				if(g[i+k][abs(j-(m-k))]>g[i][j]+1){
					g[i+k][abs(j-(m-k))]=g[i][j]+1;
					f[i+k][abs(j-(m-k))]=mp(i,j);
				}
			}
			for(int k=1;k<=j&&k<2*m;k++){
				if(k==m){
					if(g[i][j-k]>g[i][j]+1)g[i][j-k]=g[i][j]+1,f[i][j-k]=mp(i,j);
				}
				else if(k%2==0&&k/2+m<=n){
					if(g[i][j-k]>g[i][j]+2)g[i][j-k]=g[i][j]+2,f[i][j-k]=mp(i,j);
				}
			}
		}
	}
	if(g[n][0]>1e9)return cout<<-1<<endl,0;
	int p1=n,p2=0;
	a[++st]=mp(n,0);
	while(p1||p2){
		pr w=f[p1][p2];
		a[++st]=w;
		p1=w.first,p2=w.second;
	}
	reverse(a+1,a+st+1);
	//for(int o=1;o<=st;o++)cout<<a[o].first<<' '<<a[o].second<<endl;
	for(int o=1;o<st;o++){
		if(a[o+1].first>a[o].first){
			int k=a[o+1].first-a[o].first;
			if(a[o].second>=m-k){
				cout<<"? ";
				for(int i=1;i<=m-k;i++)cout<<*s[0].begin()<<' ',s[1].insert(*s[0].begin()),s[0].erase(s[0].begin());
				for(int i=a[o].first+1;i<=a[o].first+k;i++)cout<<i<<' ',s[1].insert(i);
				cout<<endl,cin>>x,ans^=x;
			}
			else {
				cout<<"? ",memset(u,0,sizeof(u));
				for(int i=1;i<=a[o].second;i++)u[*s[0].begin()]=1,cout<<*s[0].begin()<<' ',s[1].insert(*s[0].begin()),s[0].erase(s[0].begin());
				int cnt=0;
				vector<int> v;
				for(int i:s[1]){
					if(u[i])continue;
					cout<<i<<' ',v.push_back(i),cnt++;
					if(cnt==m-k-a[o].second)break;
				}
				for(int i:v)s[1].erase(i),s[0].insert(i);
				for(int i=a[o].first+1;i<=a[o].first+k;i++)cout<<i<<' ',s[1].insert(i);
				cout<<endl,cin>>x,ans^=x;
			}
		}
		else {
			int k=a[o].second-a[o+1].second;
			if(k==m){
				cout<<"? ";
				while(k--)cout<<*s[0].begin()<<' ',s[1].insert(*s[0].begin()),s[0].erase(s[0].begin());
				cout<<endl,cin>>x,ans^=x;
			}
			else {
				int p=k/2;
				vector<int> v;
				for(int i=1;i<=k;i++)v.push_back(*s[0].begin()),s[1].insert(*s[0].begin()),s[0].erase(s[0].begin());
				Ask(v);
			}
		}
	}
	cout<<"! "<<ans<<endl;
}