#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,ans=0,t[105][105],is1[100005],is2[100005];
pr a[100005];
map<int,int> is3;
int main(){
	cin>>n;
	int k=(2*n+1)/3;
	cout<<k<<'\n';
	if(n%3==1&&n){
		cout<<n<<' '<<n<<'\n';
		n--;
	}
	if(n%3==0&&n){
		cout<<n<<' '<<n<<'\n';
		n--;
	}
	if(n%3==2&&n){
		k=(2*n-1)/3;
		int t1=k,t2=k-(n-k)+1;
		while(t1>=1&&t2>=1){
			cout<<t1<<' '<<t2<<'\n';
			t1-=2,t2-=1;
		}
		int uy=n,ux=k+1;
		if(t1==0)t1=1;
		else t1=2;
		t2=t1+(uy-ux);
		while(t1<=k&&t2<=k){
			cout<<t1<<' '<<t2<<'\n';
			t1+=2,t2+=1;
		}
	}
}