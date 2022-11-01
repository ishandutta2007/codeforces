#include <bits/stdc++.h>
using namespace std;
char s[400003],ans[400002];
int cnt[256];
int st[400003],en[400003];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int sum=0;
	for(int i=1;i<=n;i++)
		cnt[s[i]]++;
	for(int i=0;i<256;i++)
		if (cnt[i]%2)
			sum++;
	if (sum>1){
		for(int i=2;i<=n;i++){
			if (n%i==0){
				int t=n/i;
				if (t%2==0 || i<sum)
					continue;
				int w=n-i;
				if (w%2)
					continue;
				//puts("WTF");
				for(int j=1;j<=i;j++)
					st[j]=en[j-1]+1,en[j]=st[j]+t-1;
				int now=1;
				for(int j=0;j<256;j++){
					if (cnt[j]%2){
						ans[(st[now]+en[now])/2]=j;
						cnt[j]--;
						now++;
					}
				}
				//puts("WTF");
				if (now>i)
					goto hell;
				for(int j=0;j<256;j++)
					while(cnt[j]){
						cnt[j]--;
						ans[(st[now]+en[now])/2]=j;
						now++;
						if (now>i)
							goto hell;
					}
				hell:;
				now=1;
				//puts("WTF");
				for(int j=0;j<256;j++){
					assert(cnt[j]%2==0);
					while(cnt[j]){
						cnt[j]-=2;
						//printf("%d %d %d\n",now,st[now],en[now]);
						//system("pause");
						ans[st[now]++]=ans[en[now]--]=j;
						if (st[now]==en[now])
							now++;
					}
				}
				printf("%d\n",i);
				for(int j=1;j<=n;j++){
					putchar(ans[j]);
					if (j%t==0)
						putchar(' ');
				}
				return 0;
			}
		}
	}else {
		puts("1");
		int st=1,en=n;
		int tat=(n+1)/2;
		for(int i=0;i<256;i++){
			if (cnt[i]%2)
				ans[tat]=i,cnt[i]--;
			for(int j=0;j<cnt[i]/2;j++)
				ans[st++]=ans[en--]=i;
		}
		puts(ans+1);
	}

}