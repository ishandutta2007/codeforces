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
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	char c[300005];
	scanf("%s",c);
	if(n%2!=0){
		printf(":(\n");
		return 0;
	}
	else{
		int l=n/2,r=n/2;
		for(int i = 0;c[i]!=0;i++){
			if(c[i]=='(')l--;
			else if(c[i]==')')r--;
		}
		if(l<0||r<0){
			printf(":(\n");
			return 0;
		}
		int cnt=0;
		for(int i = 0;c[i]!=0;i++){
			if(c[i]=='(')
			cnt++;
			else if(c[i]==')')
			cnt--;
			else{
				if(l){
					c[i]='(';
					cnt++;
					l--;
				}
				else{
					c[i]=')';
					cnt--;
					r--;
				}
			}
			if(c[i+1]&&cnt<=0){
				printf(":(\n");
				return 0;
			}
		}
		printf("%s\n",c);
	}
}