#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
const int mod=1e9+7;
int n;
bool In(int x,int y){
	if(x>=y)swap(x,y);
	return x<=0&&y>=0;
}
int Get(int x){
	int p,q;
	cout<<"? "<<x<<endl;
	cin>>p;
	cout<<"? "<<(x-1+n/2)%n+1<<endl;
	cin>>q;
	return p-q;
}
int main(){
	cin>>n;
	if(n%4)return cout<<"! "<<-1<<endl,0;
	int x=Get(1);
	if(!x)return cout<<"! "<<1<<endl,0;
	int l=1,r=1+n/2,fl=x,fr=-x;
	while(l<=r){
		int mid=(l+r)/2,u=Get(mid);
		if(!u)return cout<<"! "<<mid<<endl,0;
		if(In(u,fl))r=mid,fr=u;
		else l=mid,fl=u;
	}
	assert(0);
}