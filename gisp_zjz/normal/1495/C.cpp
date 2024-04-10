#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n,m,_;
char s[505][505];

int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf("%s",s[i]);
        int x=0; if (n%3==0) x=1;
        for (int i=x;i<n;i+=3){
			for (int j=0;j<m;j++) s[i][j]='X';
			if (i+3>=n) continue;
            bool flag=0;
            for (int j=0;j<m;j++){
				if (s[i+1][j]=='X') {s[i+2][j]='X';flag=1;break;}
				else if (s[i+2][j]=='X') {s[i+1][j]='X';flag=1;break;}
            }
            if (!flag) s[i+1][0]=s[i+2][0]='X';
        }
        for (int i=0;i<n;i++) printf("%s\n",s[i]);
	}
	return 0;
}