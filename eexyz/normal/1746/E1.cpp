#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 600005
#define IOS ios::sync_with_stdio(0)
#define ls k<<1
#define rs k<<1|1
#define l(x) (x&-x)
int a[N];
int gu(int x){
	cout<<"! "<<a[x]<<"\n";cout.flush();
	char ch;cin>>ch;cin>>ch;
	return ch==')';
}
bool ask(int l,int r){
	cout<<"? "<<r-l+1<<" ";for(int i=l;i<=r;++i)cout<<a[i]<<" ";cout<<"\n";cout.flush();
	string s;
	cin>>s;
	return s=="YES";
}
void solve(int l,int r){
//	for(int i=l;i<=r;++i)cout<<a[i]<<" ";
	if(r-l<=1){
		if(gu(l))return ;
		gu(l+1);return ;
	}
	int len=(r-l+1)/3;
	int f1=l+len,f2=l+len+len;
//	[l,f1),[f1,f2),[f2,r]
	if(r-f2+1>len+1)++f2;
	int q=ask(f2,r);
	if(q==0)q=ask(f2,r);
	if(q==0){
		solve(l,f2-1);
	}
	else{
		if(ask(f1,f2-1))solve(f1,r);
		else{
			for(int i=f2;i<=r;++i)a[i-f2+f1]=a[i];
			solve(l,r-f2+f1);
		}
	}
}
int n;
int main(){
	IOS;
	cin>>n;for(int i=1;i<=n;++i)a[i]=i;
	solve(1,n);
}