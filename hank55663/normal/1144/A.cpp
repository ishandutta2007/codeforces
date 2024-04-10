#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char c[105];
		scanf("%s",c);
		int len=strlen(c);
		sort(c,c+len);
		int ok=1;
		for(int i=1;c[i]!=0;i++){
			if(c[i]==c[i-1]){
				ok=0;
			}
			if(c[i]!=c[i-1]+1){
				ok=0;
			}
		}
		if(ok==0){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
}