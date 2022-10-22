#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 100010 
#define cout cerr
#define FR first
#define SE second
int num[Maxn],ans[Maxn];
vector<int> vec[Maxn];

/*inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}*/

int H(int type,int x,int y){
	if(type==0)printf("AND %d %d\n",x,y);
	if(type==1)printf("OR %d %d\n",x,y);
	if(type==2)printf("XOR %d %d\n",x,y); 
	fflush(stdout); 
	int res;scanf("%d",&res);
	return res;
}

void output(){
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	puts("");
	fflush(stdout);
}

int main(){
	scanf("%d",&n);
	vec[0].push_back(1);
	for(int i=2;i<=n;++i)num[i]=H(2,1,i),vec[num[i]].push_back(i);
	for(int i=0;i<n;++i)
		if(vec[i].size()>=2){
			int at=vec[i][0];
			ans[vec[i][0]]=ans[vec[i][1]]=H(0,vec[i][0],vec[i][1]);
			for(int j=1;j<=n;++j)ans[j]=ans[at]^(num[j]^num[at]);
			output();
			return 0;
		}
	int x=vec[1][0],y=vec[2][0];
	ans[1]=H(0,1,x)|H(0,1,y);
	for(int i=2;i<=n;++i)ans[i]=ans[1]^num[i];
	output();
	return 0;
}