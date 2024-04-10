#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string f[505][2],a;
void upd(string &x,string y){
	x=min(x,y);
}
string cycshift(string x,int p,int v){
	if(p<1||p>x.size())return "~";
	return x[p-1]=(x[p-1]-'a'+v)%m+'a',x;
}
string swp(string x,int p,int q){
	if(min(p,q)<1||max(p,q)>x.size())return "~";
	return swap(x[p-1],x[q-1]),x;
}
void Solve(){
	scanf("%d%d",&n,&m),cin>>a,a+="~",a=" "+a,f[0][0]=a[1],f[0][1]="~";
	for(int i=1;i<=n;i++){//i 
		f[i][0]=f[i][1]='~';
		//O 
		upd(f[i][0],f[i-1][0]+a[i+1]);
		upd(f[i][0],f[i-1][1]+a[i+1]);
		//U,D
		upd(f[i][0],cycshift(f[i-1][0],i,1)+a[i+1]);
		upd(f[i][0],cycshift(f[i-1][0],i,m-1)+a[i+1]);
		upd(f[i][0],cycshift(f[i-1][1],i-1,1)+a[i+1]);
		upd(f[i][0],cycshift(f[i-1][1],i-1,m-1)+a[i+1]);
		//L
		upd(f[i][0],swp(f[i-1][0],i,i-1)+a[i+1]);
		upd(f[i][0],swp(f[i-1][1],i-1,i-2)+a[i+1]);
		//R
		upd(f[i][1],f[i-1][0]+a[i]);
		f[i][1][i-1]=a[i+1];
	}
	for(int i=0;i<n;i++)cout<<f[n][0][i];
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}