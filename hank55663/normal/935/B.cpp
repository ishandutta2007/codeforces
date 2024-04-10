#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	int x=0,y=0;
	char c[100005];
	scanf("%s",c);
	int ok=-1;
	for(int i =0;c[i]!=0;i++){
		if(c[i]=='U')
		x++;
		else
		y++;
		if(x>y){
			if(ok!=0){
				ok=0;
				cnt++;
			}
		}
		else if(x<y){
			if(ok!=1){
				ok=1;
				cnt++;
			}
		}
	}

	cnt--;
	printf("%d\n",cnt);
}