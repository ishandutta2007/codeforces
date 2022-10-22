#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int t[MAXN],n,f11[MAXN],f21[MAXN],f12[MAXN],f22[MAXN],rec;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		if(t[i]==1){
			f11[i]=f11[i-1]+1;
		}
		else{
			f21[i]=f21[i-1]+1;
		}
	}
	for(int i=n;i>=1;i--){
		if(t[i]==2){
			f22[i]=f22[i+1]+1;
		}
		else{
			f12[i]=f12[i+1]+1;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==2){
			rec=max(rec,min(f22[i],f11[i-1])*2);
			rec=max(rec,min(f21[i],f12[i+1])*2);
		}
		else{
			rec=max(rec,min(f11[i],f22[i+1])*2);
			rec=max(rec,min(f12[i],f21[i-1])*2);
		}
	}
	printf("%d\n",rec);
}