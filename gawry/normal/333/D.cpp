#include<cstdio>
#include<cstdlib>
#include<iostream>
#include <cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

#define MAX_BUF 1024*1024

char buf_in[MAX_BUF],*next_in,buf_out[MAX_BUF],*next_out;

void read_buf() {
	buf_in[fread(buf_in,1,MAX_BUF-1,stdin)]=0;
	next_in=buf_in;
}

void read_char() {
	next_in++;
	if (!*next_in)
		read_buf();
}

bool read_eof() {
	return !*next_in;
}

int read_int() {
	int x=0;
	
	while (*next_in<'0' || *next_in>'9')
		read_char();
	while (*next_in>='0' && *next_in<='9') {
		x=10*x+*next_in-'0';
		read_char();
	}
	
	return x;
}

double read_double() {
	double x=0.0,p=1.0;
	
	while ((*next_in<'0' || *next_in>'9') && *next_in!='-')
		read_char();
	if (*next_in=='-')
		return -read_double();
	while (*next_in>='0' && *next_in<='9') {
		x=10*x+*next_in-'0';
		read_char();
	}
	if (*next_in=='.') {
		read_char();
		while (*next_in>='0' && *next_in<='9') {
			x=10*x+*next_in-'0';
			p*=10.0;
			read_char();
		}
	}
	
	return x/p;
}

void write_buf() {
	fwrite(buf_out,1,next_out-buf_out,stdout);
	next_out=buf_out;
}

void write_char(char c) {
	*next_out++=c;
	if (next_out-buf_out==MAX_BUF)
		write_buf();
}

void _write_int(int x) {
	if (x) {
		_write_int(x/10);
		write_char('0'+x%10);
	}
}

void write_int(int x) {
	if (x<0) {
		write_char('-');
		x=-x;
	}
	if (!x)
		write_char('0');
	else
		_write_int(x);
}

void write_string(const char *c) {
	while (*c)
		write_char(*c++);
}

void init() {
	read_buf();
	next_out=buf_out;
}

void deinit() {
	write_buf();
}

using namespace std;
typedef pair<short int,short int> p2;
p2 s[1007*1007];
int t[1007][1007],deg[1007],cur[1007][1007],seen[1007][1007];
bool cmp(const p2 &a,const p2 &b){
  return t[a.first][a.second]<t[b.first][b.second];
}
int main(){
	init();
	int n=read_int(),m=read_int();
	//scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)t[i][j]=read_int(),s[m*i+j]=p2(i,j);//scanf("%d",&t[i][j]);//=rand()%1000000000;
  unsigned int ans=0;
  int k=max((int)(n*m-n-m*sqrt(n)),0);
  nth_element(s,s+k,s+m*n,cmp);
  for(int i=0;i<m;i++)for(int j=0;j<m;j++)seen[i][j]=-1;
  sort(s+k,s+m*n,cmp);
  for(int i=m*n-1;i>=k;i--){
    int x=s[i].first,y=s[i].second;
    for(int j=0;j<deg[x];j++){
      if(seen[y][cur[x][j]]>=0){
        printf("%d\n",(unsigned int)t[x][y]);
        return 0;
      }
      seen[y][cur[x][j]]=x;
      seen[cur[x][j]][y]=x;
    }
    cur[x][deg[x]++]=y;
  }
  return 1;
}