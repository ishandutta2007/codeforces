#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
char t[500005];
int f[500005];
void KMP(){
	int j=-1;
	f[0]=-1;
	for(int i=1;t[i]!=0;i++){
		while(j!=-1&&t[j+1]!=t[i])j=f[j];
		if(t[j+1]==t[i])j++;
		f[i]=j;
	}
}
int main(){
	char s[500005];
	int cnt[2];
	MEM(cnt);
	scanf("%s",s);
	for(int i=0;s[i]!=0;i++){
		cnt[s[i]-'0']++;
	}
	scanf("%s",t);
	KMP();
	int len=strlen(t);
	for(int i=0;t[i]!=0;i++){
		if(cnt[t[i]-'0']){
			printf("%d",t[i]-'0');
			cnt[t[i]-'0']--;
		}
		else{
			goto end;
		}
	}
	while(true){
		int now=f[len-1]+1;
		while(now!=len){
			if(cnt[t[now]-'0']){
				printf("%d",t[now]-'0');
				cnt[t[now]-'0']--;
				now++;
			}
			else{
				goto end;
				break;
			}
		}
	}
	end:
	while(cnt[0]--)printf("0");
	while(cnt[1]--)printf("1");
}