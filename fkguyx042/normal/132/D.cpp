#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#define fi first
#define se second
#define mk make_pair
using namespace std;

char s[1000005];
int n;
vector<pair<int,int> > ans;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=n;i>=0;i--){
		if(s[i]=='1'){
			if(s[i-1]=='1'){
				int j=i;
				while(j>=0 && s[j]=='1'){
					s[j]='0';
					--j;
				}
				s[j]='1';
				ans.push_back(mk(n-i,-1));
			}else{
				ans.push_back(mk(n-i,1));
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(ans[i].se==-1) printf("-2^%d\n",ans[i].fi);
		else printf("+2^%d\n",ans[i].fi);
	}
	return 0;
}