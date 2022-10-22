#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int res=1;
	scanf("%d",&n);
	int lasta=0,lastb=0;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a<lastb) {
		swap(lasta,a);
		swap(lastb,b);
			continue;
		}
		if(b<lasta){
			swap(lasta,a);
		swap(lastb,b);
			continue;
		} 
		if(lasta<=lastb&&a>=b){
			res+=b-lastb+1;
			if(lasta==lastb) res--;
			swap(lasta,a);
		swap(lastb,b);
			continue;
		}
		if(lastb<=lasta&&b>=a){
			res+=a-lasta+1;
			if(lastb==lasta) res--; 
			swap(lasta,a);
		swap(lastb,b);
			continue;
		}
		if(a>=lastb&&lasta<=lastb){
			res+=a-lastb+1;
			swap(lasta,a);
			swap(lastb,b);
			continue;
		}
		if(a>=b&&lasta<=b){
			res+=b-lasta+1;
		}
		swap(lasta,a);
		swap(lastb,b);
	}
	printf("%d\n",res);
	return 0;
}