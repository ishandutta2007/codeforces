#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int a[120],b[120];
void guass(int x){
	int y=x;
	for(int i=t-1;i>=0;--i){
		b[i]=y%k;
		y/=k;
	}
	int w=0;
	for(int i=0;i<t;++i){
		int z= (x%2?a[i]-b[i]:a[i]+b[i]);
		z=(z+k)%k;
		w=w*k+z;
		a[i]=(-a[i]+z+k)%k;
	}
	cout<<w<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		memset(a,0,sizeof a);
		int w=n*k;
		t=0;
		while(w)t++,w/=k;
		++t;
		for(int i=0;i<n;++i){
			guass(i);
			int r;
			cin>>r;
			if(r)break;
		}
	}
}