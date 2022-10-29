#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
typedef __int64  LL ;
const int MAXN = 100100;
const LL inf = 1000000000000000ll ;
LL n , len ,k ;
LL a[MAXN] ;
priority_queue< pair<LL,LL> ,vector< pair<LL,LL> > , greater< pair<LL,LL> > > que ;
priority_queue< pair<LL,LL> ,vector< pair<LL,LL> > , less< pair<LL,LL> > > que1;

bool vis[MAXN] ;

void solve(){
	LL i ,j ,f , c ,v ,b;
	LL ans = -inf ;
	for(f=0;f<2;f++){		
		if(f == 1){
			for(i=1;i<=n;i++){
				a[i] = -a[i] ;
			}
		}
		c = 0 ;
		LL res = 0 ;
		while(!que.empty()) que.pop() ;
		memset(vis, 0 ,sizeof(vis));
		while(!que1.empty()) que1.pop() ;
		
		for(i=1;i<=n;i++){			
			if( a[i]<0 ){
				if( c==k ){
					if( !que.empty() && -a[i]>que.top().first ){
						v = que.top().first ;		//val 
						b = que.top().second ;		//number
						que1.push( make_pair(v,b) );
						vis[b] = 0 ;
						que.pop() ;	
						que.push( make_pair( -a[i] , i) ) ;		
						vis[i] = 1 ;
						res -= 2*v ;
						res -= a[i] ;
					}
					else{
						res += a[i] ;
						que1.push( make_pair( -a[i] , i) );
					}
				}
				else{
					que.push( make_pair(-a[i] , i));
					vis[i] = 1 ;
					c++ ;
					res -= a[i] ;
				}
			}	
			else
				res += a[i] ;
			if(i == len)	break ;
		}
		if(ans < res)	ans = res ;
		
		for(i++ ;i<=n;i++){			
			if( vis[i-len] == 1){
				res += a[i-len] ;
				c -- ;
			}
			else{
				res -= a[i-len] ;
			}
			while(!que1.empty() && c!=k){
				v = que1.top().first ;
				b = que1.top().second ;
				if(b <= i-len)	que1.pop() ;
				else{
					res += v*2 ;
					c++ ;		
					que1.pop() ;
					que.push( make_pair(v,b) );
					vis[b] = 1 ;
				}
			}
			if( a[i] < 0 ){
				if( c==k ){
					while(!que.empty() && que.top().second <= i-len ){
				 		que.pop() ;
					}
					if(!que.empty() && que.top().first < -a[i]){
						v = que.top().first ;
						b = que.top().second ;
						vis[ b ] =  0;
						que.pop() ;
						que1.push( make_pair(v,b) ) ;
						que.push( make_pair(-a[i] , i)) ;
						vis[i] = 1;
						res -= 2 * v ;
						res -= a[i] ;
					}
					else{
						res += a[i] ;
						que1.push( make_pair( -a[i] , i) );
					}
				}
				else{
					que.push( make_pair(-a[i] , i) ) ;
					vis[i] = 1;
					res -= a[i] ;
					c++ ;
				}
			}
			else{
				res += a[i] ;
			}	
			if( ans < res )	ans = res ;
		}
	}
	printf("%I64d\n",ans);
}	

int main(){
	while(scanf("%I64d%I64d",&n,&len) == 2){
		for(int i=1;i<=n;i++){
			scanf("%I64d",&a[i]);
		}			
		scanf("%I64d",&k);
		solve() ;
	}
	return 0 ;
}