#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n;
int cnt;
bool od=0;
vi oper;

int main() {
	scanf("%d",&n);
	//printf("%d\n",n);
	int p = 30;
	for(int i=0; i<20;i++){
		while((1<<p)>n) {
			p--;
		}
		oper.PB(p+1);
		n = n^((1<<(p+1))-1);
		if((n^((1<<p)-1))==0) {
			od=1;
			break;
		}
		n++;
		if(((n^((1<<p)-1))==0)) break;
		//printf("%d %d\n",n,p+1);
	}
	printf("%d\n",(int)oper.size()*2-od);
	for(auto it:oper) printf("%d ",it);
}