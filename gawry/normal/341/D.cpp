#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define MAX_BUF 1024



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



long long read_int() {

  long long x=0;



  while (*next_in<'0' || *next_in>'9')

    read_char();

  while (*next_in>='0' && *next_in<='9') {

    x=10*x+*next_in-'0';

    read_char();

  }



  return x;

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



void _write_int(long long x) {

  if (x) {

    _write_int(x/10);

    write_char('0'+x%10);

  }

}



void write_int(long long x) {

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



#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

const int POWER=1<<10;
#define low(x) ((x)&((x)^((x)-1)))
struct tree {
	long long t[POWER][POWER];
	tree(){
		memset(t,0,sizeof(t));
	}
	long long sum(int x,int y){
		long long res=0;
		for(int curx=x;curx>0;curx-=curx&-curx)
		for(int cury=y;cury>0;cury-=cury&-cury)
			res^=t[curx][cury];
		return res;
	}
	void update(int x,int y,long long v){
		for(int curx=x;curx<POWER;curx+=curx&-curx)
		for(int cury=y;cury<POWER;cury+=cury&-cury)
			t[curx][cury]^=v;
	}
} t[2][2];
long long sum(int x,int y){
	return t[x%2][y%2].sum(x,y);
}
void update(int x0,int y0,int x1,int y1,long long v){
	for(int dx=0;dx<=1;dx++)for(int dy=0;dy<=1;dy++){
		if(x1%2!=dx&&y1%2!=dy)t[dx][dy].update(x1,y1,v);
		if(x1%2!=dx&&y0%2==dy)t[dx][dy].update(x1,y0,v);
		if(x0%2==dx&&y1%2!=dy)t[dx][dy].update(x0,y1,v);
		if(x0%2==dx&&y0%2==dy)t[dx][dy].update(x0,y0,v);
	}
}
long long sum(int x0,int y0,int x1,int y1){
	long long res=0;
	res^=sum(x1,y1);
	if(x0>0)res^=sum(x0-1,y1);
	if(y0>0)res^=sum(x1,y0-1);
	if(x0>0&&y0>0)res^=sum(x0-1,y0-1);
	return res;
}
main(){
	int n,m,z,x0,y0,x1,y1;
	long long v;
	init();
	n=read_int();m=read_int();
	//scanf("%d %d",&n,&m);
	while(m--){
		z=read_int();
		x0=read_int();y0=read_int();x1=read_int();y1=read_int();
//		scanf("%d %d %d %d %d",&z,&x0,&y0,&x1,&y1);
		if(z==1){
			write_int(sum(x0,y0,x1,y1));
			write_char('\n');
		}else{
			v=read_int();
//			scanf("%d",&v);
			update(x0,y0,x1,y1,v);
		}
	}
	deinit();
}