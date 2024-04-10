#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
char a[4][4],b[4][4];
const int d[4][2]={{1,1},{1,2},{2,2},{2,1}};
string p,q;
int main(){
	scanf("%s",a[1]+1);
	scanf("%s",a[2]+1);
	scanf("%s",b[1]+1);
	scanf("%s",b[2]+1);
	for(int i=0;i<4;++i){
		int x=d[i][0],y=d[i][1];
		if(a[x][y]^'X')p+=a[x][y];
		if(b[x][y]^'X')q+=b[x][y];
	}
	bool ok=false;
	for(int i=0;i<3;++i){
		if(p==q)ok=true;
		p+=p.front();
		p=p.substr(1,3);
	} 
	printf(ok?"Yes":"No");
	return 0;
}