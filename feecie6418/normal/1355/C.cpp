#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll ans=0;
int a,b,c,d;
int main(){
	cin>>a>>b>>c>>d;
	if(c-b>d-c)c=b+(d-c);
	for(int i=a;i<=b;i++){
		int x=c-b,y=d-c;
		if(i<=x+1)ans+=1ll*i*(i+1)/2;
		else if(i<=y+1)ans+=1ll*(c-b+1)*(b+i-c+i)/2;
		else {
			if(i>d-b){
				ans+=1ll*(d-c+1)*(c-b+1);
				continue;
			}
			ans+=1ll*(d-b-i+2)*(d-c+1+b+i-c)/2+1ll*(d-c+1)*(c-d+i-1);
		}
		//cout<<i<<' '<<ans<<endl;
	}
	cout<<ans;
}