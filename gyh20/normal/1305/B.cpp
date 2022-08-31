#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int t,n,a[1002],cnt[1002],ans[1002][1002],num,lst;
char s[1002];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	while(1){
		int l=1,r=n;++num;
		while(l<r){
			while(s[l]==')'||s[l]=='$')++l;
			while(s[r]=='('||s[r]=='$')--r;
			if(l<r){
				ans[num][++cnt[num]]=l;
				ans[num][++cnt[num]]=r;
				s[l]=s[r]='$';
				++l;
				--r;
			}
		}
		if(!cnt[num])break;
	}
	printf("%d\n",num-1);
	for(re int i=1;i<num;++i){
		printf("%d\n",cnt[i]);
		sort(ans[i]+1,ans[i]+cnt[i]+1);
		for(re int j=1;j<=cnt[i];++j){
			printf("%d ",ans[i][j]);
		}
		putchar('\n');
	}
}