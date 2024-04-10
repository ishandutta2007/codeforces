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
#define sqr(x) ((x)*(x))
#define pdd pair<double,double> 
int main(){
	int n;
	scanf("%d",&n);
	char c[100005];
	scanf("%s",c);
	int cnt=0;
	for(int i =0;i<=n-11;i++){
		if(c[i]=='8')
			cnt++;
		else
			cnt--;
	}
	if(cnt>0)printf("YES\n");
	else printf("NO\n");
}