#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int B,k,sum=0;
int main(){
	cin>>B>>k;
	for(int i=1,x;i<=k;i++)cin>>x,sum=(sum*B+x)%2;
	cout<<(sum?"odd":"even");
}