#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,n;
		scanf("%d %d %d",&a,&b,&n);
		for(int i = 0;;i++){
			if(a>n||b>n){
				printf("%d\n",i);
				break;
			}
			if(a>b)swap(a,b);
			a+=b;
		}
	}
	return 0;
}