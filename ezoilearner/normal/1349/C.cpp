#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> mp;
typedef long long ll;
int n,m,t;
#define Maxn 1005
#define V 1000010
char str[Maxn][Maxn];
int d[Maxn][Maxn];
mp Q[V];
int hd,tl;
int nx[4]={-1,1,0,0};
int ny[4]={0,0,-1,1};
int main(){
	scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;++i){
		scanf("%s",str[i]+1);
		for(int j=1;j<=m;++j)d[i][j]=-1;
    }
    hd=0;tl=0;
    for(int i=1;i<=n;++i)
	   for(int j=1;j<=m;++j){
	       bool flag=false;
		   for(int k=0;k<4;++k)
		       if(i+nx[k]<=n&&i+nx[k]>=1&&j+ny[k]<=m&&j+ny[k]>=1&&str[i][j]==str[i+nx[k]][j+ny[k]]){
					flag=true;
					break;
		       }	   
		    if(flag){
				Q[tl++]=make_pair(i,j);
				d[i][j]=0;
		    }
       }
    while(hd<tl){
		mp u=Q[hd];hd++;
		for(int i=0;i<4;++i){
			int tx=u.first+nx[i],ty=u.second+ny[i];
			if(tx>=1&tx<=n&&ty>=1&&ty<=m&&d[tx][ty]==-1){
				d[tx][ty]=d[u.first][u.second]+1;
				Q[tl++]=make_pair(tx,ty); 
			}
		}
    }
    int num1,num2;
    ll num;
    while(t--){
		scanf("%d%d%lld",&num1,&num2,&num);
		if(d[num1][num2]==-1)printf("%c\n",str[num1][num2]);
		else{
			if(num<=d[num1][num2])printf("%c\n",str[num1][num2]);
			else{
				int c=str[num1][num2]-'0';
				if((num-d[num1][num2])&1)c^=1;
				char p='0'+c;
				printf("%c\n",p);
			}
		}
    }
	return 0;
}