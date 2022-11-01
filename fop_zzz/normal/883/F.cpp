#include <bits/stdc++.h>
using namespace std;
bool equal(char *s1,char *s2){
	return !strcmp(s1,s2);
}
char s[403][52];
int fa[402];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
char tmp[403];
bool del[403];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",tmp);
		int w=strlen(tmp);
		for(int j=0;j<w;j++){
			del[j]=0;
			if (tmp[j]=='h'){
				int k=j-1;
				while(k>=0 && tmp[k]=='k')
					del[k]=true,k--;
			}
		}
		int cur=0;
		for(int j=0;j<w;j++)
			if (!del[j]){
				if (tmp[j]=='u')
					s[i][cur++]='o',s[i][cur++]='o';
				else s[i][cur++]=tmp[j];
			}
		fa[i]=i;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if (equal(s[i],s[j]))
				fa[getf(i)]=getf(j);
	int cnt=0;
	for(int i=0;i<n;i++)
		if (fa[i]==i)
			cnt++;
	printf("%d",cnt);
}