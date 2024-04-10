#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 200020
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
int n,cnta,cntb,lasa,lasb;
char a[N],b[N];
vector<pair<int,int> > ans;
int main(){
	n=read();
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;i++){
		if(a[i]=='a')cnta++;
		else cntb++;
		if(b[i]=='a')cnta++;
		else cntb++;
	}
	if((cnta&1)||(cntb&1)){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==b[i])continue;
		if(a[i]=='a'){
			if(lasa){
				ans.push_back(make_pair(lasa,i));
				lasa=0;
			}
			else{
				lasa=i;
			}
		}
		else{
			if(lasb){
				ans.push_back(make_pair(lasb,i));
				lasb=0;
			}
			else{
				lasb=i;
			}
		}
	} 
	if(lasa&&lasb){
		ans.push_back(make_pair(lasa,lasa));
		ans.push_back(make_pair(lasa,lasb));
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	} 
	return 0;
}