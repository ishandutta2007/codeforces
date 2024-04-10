#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}

#define N (1<<21)
struct DJS{
  int p[ N ] , sz[ N ] , usd[ N ];
  void init( int n ){
    for( int i = 1 ; i <= n ; i ++ )
      p[ i ] = i , sz[ i ] = 1 , usd[ i ] = 0;
  }
  int f( int x ){
    return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
  }
  void uni( int x , int y ){
    x = f( x );
    y = f( y );
    if( x == y ) return;
    p[ x ] = y;
    sz[ y ] += sz[ x ];
    usd[ y ] += usd[ x ];
  }
} djs;
struct Arc{
  int to , nxt , id;
  Arc(){}
  Arc( int _to , int _nxt , int _id ) :
    to( _to ) , nxt( _nxt ) , id( _id ) {}
} r[ N + N ];
int n , m , c[ N ][ 2 ] , from[ N ] , deg[ N ];
void init(){
  //scanf( "%d%d" , &n , &m );
  //for( int i = 1 ; i <= n ; i ++ )
    //scanf( "%d%d" , &c[ i ][ 0 ] , &c[ i ][ 1 ] );
}
//int ans[ N ];
//bool byen[ N ] , byem[ N ];
//void go( int now ){
  //while(true){
    //for( int i = from[ now ] ; i ; i = r[ i ].nxt ){
      //if( byen[ i / 2 ] ) continue;
      //byen[ i / 2 ] = true;
      //byem[ now ] = true;
      //ans[ i / 2 ] = r[ i ].id;
      //if( !byem[ r[ i ].to ] ){
        //now=r[i].to;
        //break;
      //}
        ////go( r[ i ].to );
      //return;
    //}
  //}
//}
//int Q[N], qf, qt;
//void find_ans(){
  ////queue< int > Q;
  //qf=qt=0;
  //for( int i = 1 ; i <= m ; i ++ )
    //if( deg[ i ] == 1 )
      ////Q.push( i );
      //Q[qt++]=i;
  ////while( Q.size() ){
  //while( qf < qt ){
    ////int tn = Q.front(); Q.pop();
    //int tn=Q[qf++];
    //for( int i = from[ tn ] ; i ; i = r[ i ].nxt ){
      //if( byen[ i / 2 ] ) continue;
      //byen[ i / 2 ] = true;
      //byem[ tn ] = true;
      //ans[ i / 2 ] = r[ i ].id;
      //deg[ r[ i ].to ] --;
      //if( deg[ r[ i ].to ] == 1 )
        ////Q.push( r[ i ].to );
        //Q[qt++]=r[i].to;
    //}
  //}
  //for( int i = 1 ; i <= m ; i ++ )
    //if( !byem[ i ] && deg[ i ] > 0 )
      //go( i );
//}
bool solve(){
  djs.init( m );
  //for(int i=1; i<=n; i++) ans[i]=0;
  //for(int i=1; i<=m; i++) deg[i]=from[i]=0;
  //for(int i=0; i<=n*2+1; i++) byen[i]=0;
  //for(int i=1; i<=m; i++) byem[i]=0;
  for( int i = 1 ; i <= n ; i ++ ){
    djs.uni( c[ i ][ 0 ] , c[ i ][ 1 ] );
    int x = djs.f( c[ i ][ 0 ] );
    if( djs.sz[ x ] - djs.usd[ x ] == 0 ) return false;
    djs.usd[ x ] ++;
    //r[ i << 1 ] = Arc( c[ i ][ 1 ] , from[ c[ i ][ 0 ] ] , 1 );
    //from[ c[ i ][ 0 ] ] = i << 1;
    //r[ 1 + ( i << 1 ) ] = Arc( c[ i ][ 0 ] , from[ c[ i ][ 1 ] ] , 2 );
    //from[ c[ i ][ 1 ] ] = 1 + ( i << 1 );
    //deg[ c[ i ][ 0 ] ] ++;
    //deg[ c[ i ][ 1 ] ] ++;
  }
  return true;
  //for(int i=1; i<=m; i++)
    //if(i == djs.f(i) and djs.usd[i] > djs.sz[i])
      //return false;
  //return true;
  ////find_ans();
  //for(int i=1; i<=n; i++)
    //if(ans[i] == 0)
      //return false;
  //return true;
}

int nn, a[N], b[N], la[N], lb[N];
vector<int> li;
bool good(int til){
  n=nn;
  m=li.size();
  for(int i=0; i<nn; i++){
    c[i+1][0]=la[i] <= til ? la[i] : lb[i];
    c[i+1][1]=lb[i] <= til ? lb[i] : la[i];
  }
  return solve();
}
int main(){
  nn=getint();
  for(int i=0; i<nn; i++){
    a[i]=getint();
    b[i]=getint();
    li.push_back(a[i]);
    li.push_back(b[i]);
  }
  sort(li.begin(), li.end());
  li.resize(unique(li.begin(), li.end())-li.begin());
  int atleast=1;
  for(int i=0; i<nn; i++){
    la[i]=lower_bound(li.begin(), li.end(), a[i])-li.begin()+1;
    lb[i]=lower_bound(li.begin(), li.end(), b[i])-li.begin()+1;
    atleast=max(atleast,
                min(la[i], lb[i]));
  }
  int atmst=li.size(), aa=atmst+1;
  while(atleast <= atmst){
    int mid=(atleast+atmst)>>1;
    if(good(mid)) aa=mid, atmst=mid-1;
    else atleast=mid+1;
  }
  li.push_back(-1);
  printf("%d\n", li[aa-1]);
}