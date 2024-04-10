#include<cstdio>
#include<cstring>
using namespace std;

const int N=2e5+100;
char s[N];int Cnt[50];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		
		memset(Cnt,0,sizeof(Cnt));
		
		for(int i=1;i<=len;i++) Cnt[s[i]-'a']++;
		
		int Ans;
		for(int i=1;i<=len;i++){
			if(Cnt[s[i]-'a']==1){
				Ans=i;break;
			}
			Cnt[s[i]-'a']--;
		}
		for(int i=Ans;i<=len;i++) printf("%c",s[i]);
		printf("\n");
	}
	
	return 0;
}