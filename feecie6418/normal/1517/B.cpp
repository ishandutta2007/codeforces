#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[105][105];
struct Pos{
	int x,y,z;
}b[10005],c[105][105];
const bool operator <(const Pos i,const Pos j){
	if(i.z!=j.z)return i.z<j.z;
	if(i.x!=j.x)return i.x<j.x;
	return i.y<j.y;
}
bool operator ==(Pos i,Pos j){
	return !(i<j)&&!(j<i);
}
void Solve(){
	cin>>n>>m;
	int C=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j],b[++C]=c[i][j]={i,j,a[i][j]};
	sort(b+1,b+C+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int flag=0;
			for(int k=1;k<=m;k++)if(c[j][k]==b[i])flag=k;
			if(flag){
				swap(c[j][flag],c[j][i]);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<c[i][j].z<<' ';
		puts("");
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}