#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int ans=min(a/3,min(b/2,c/2));
	a-=ans*3;
	b-=ans*2;
	c-=ans*2;
	int sum=0;
	for(int i = 0;i<7;i++){
		int k=i;
		int cnt=0;
		int aa=0,bb=0,cc=0;
		while(1){
			//printf("%d %d %d %d %d %d %d\n",i,aa,bb,cc,a,b,c);
			if(k==0||k==3||k==6){
				aa++;
			}
			if(k==1||k==5){
				bb++;
			}
			if(k==2||k==4){
				cc++;
			}
			if(cc<=c&&bb<=b&&aa<=a){
				cnt++;
			}
			else{
				break;
			}
			k=(k+1)%7;
		}
		sum=max(sum,cnt);
	}
	printf("%d\n",sum+ans*7);
}