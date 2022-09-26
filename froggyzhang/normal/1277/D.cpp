#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
#define N 200020
map<string,int> mp;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
string s;
int T,n,p00,p11,p10,p01,no0,no1;
int type[N],d[N];
int main(){
	T=read();
	while(T--){
		n=read();p00=p11=p10=p01=0;
		int ans=0;mp.clear();
		bool QAQ=false;
		for(int i=1;i<=n;i++){
			d[i]=0;
			cin>>s;
			bool tmp=false;
			if(mp[s])reverse(s.begin(),s.end()),++ans,tmp=true,d[i]=1,d[mp[s]]=1; 
			if(mp[s])QAQ=true;
			mp[s]=i;
			int len=s.length();
			if(s[0]=='0'&&s[len-1]=='0')++p00,type[i]=1;
			if(s[0]=='0'&&s[len-1]=='1')++p01,type[i]=2;
			if(s[0]=='1'&&s[len-1]=='0')++p10,type[i]=3;
			if(s[0]=='1'&&s[len-1]=='1')++p11,type[i]=4;
			reverse(s.begin(),s.end());
			if(mp[s])tmp=true,d[i]=1,d[mp[s]]=1;
			if(tmp){
				if((s[0]=='0'&&s[len-1]=='0')||(s[0]=='1'&&s[len-1]=='1'))no0++;
				else no1++;
			}
		}
		p00=min(1,p00),p11=min(1,p11);
		int ooo=max(abs(p01-p10)/2,0);
		if(QAQ){
			printf("-1\n");
			continue;
		}
		if(p00&&p11&&p01==0&&p10==0){
			if(no0){
				printf("-1\n");
				continue;
			}
			else{
				printf("%d\n",min(p00,p11));
				if(p00>p11){
					for(int i=1;i<=n;i++){
						if(type[i]==4){
							printf("%d ",i);
						}
					}
				}
				else{
					for(int i=1;i<=n;i++){
						if(type[i]==1){
							printf("%d ",i);
						}
					}
				}
				printf("\n");
			}
		}
		printf("%d\n",ooo);
		if(ooo){
			if(p01>p10){
				for(int i=1;i<=n;i++){
					if(!ooo)break;
					if(type[i]==2&&!d[i])printf("%d ",i),--ooo;
				} 
			}
			else{
				for(int i=1;i<=n;i++){
					if(!ooo)break;
					if(type[i]==3&&!d[i])printf("%d ",i),--ooo;
				}
			}
		}
		printf("\n");
	}
	return 0;
}