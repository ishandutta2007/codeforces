#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int n;
	scanf("%d",&n);
	char c[100005];
	scanf("%s",c);
	int last=-1;
	for(int i = 0;c[i]!=0;i++){
		for(int j = 2;j>=0;j--){
			if(j==last)continue;
			if(j==2&&c[i]=='1'){
				printf("1");
				last=2;
				break;
			}
			if(j==1){
				if(c[i]=='0')
				printf("1");
				else
				printf("0");
				last=1;
				break;
			}
			if(j==0){
			printf("0");
			last=0;
			}
		}
	}
	printf("\n");
    return true;
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/