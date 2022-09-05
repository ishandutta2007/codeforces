#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define pb push_back

int res,t[5];


int main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		t[a]++;
	}
	while(t[1]){
		if(t[2]){
			t[3]++;
			t[2]--;
			t[1]--;
			t[0]++;
			res++;
		}
		else if(t[1]>=3){
			t[1]-=3;
			t[3]++;
			res+=2;
		}
		else if(t[1]==1){
			if(t[3]){
				t[3]--;t[1]--;t[4]++;
				res++;
			}
			else if(t[4]>=2){
				t[1]--;
				t[3]+=3;
				t[4]-=2;
				res+=2;
			}
			else{
				printf("-1");
				return 0;
			}
		}
		else{
			//t[1]==2
			if(t[3]>=2||t[4]){
				t[1]=0;
				res+=2;
			}
			else{
				printf("-1");
				return 0;
			}
		}
	}
	while(t[2]>=3){
		t[2]-=3;
		t[0]++;
		t[3]+=2;
		res+=2;
	}
	if(t[2]==2)res+=2;
	else if(t[2]==1){
		if(t[4])res++;
		else if(t[3]>=2)res+=2;
		else{
			printf("-1");
			return 0;
		}
	}
	printf("%d",res);
	return 0;
}