    #include <cstdio>
    #include <algorithm>
    #include <cstring>
    #include <iostream>
    #include <vector>
    #include <bitset>
    #include <cmath>
    #include <queue>
    #include <list>
    #include <map>
    #include <set>
    #include <unordered_map>
    using namespace std;
    typedef long long ll;
    const int maxn=100050;
    struct point{
    	int x,y;
    	point(int x=0,int y=0):x(x),y(y){}
    };
    typedef point vctor;
    vctor operator + (vctor a,vctor b){
    	return vctor(a.x+b.x,a.y+b.y);
    }
    vctor operator - (vctor a,vctor b){
    	return vctor(a.x-b.x,a.y-b.y);
    }
    vctor operator * (vctor a,double k){
    	return vctor(a.x*k,a.y*k);
    }
    vctor operator / (vctor a,double k){
    	return vctor(a.x/k,a.y/k);
    }
    bool operator != (vctor a,vctor b){
    	return a.x!=b.x||a.y!=b.y;
    }
    point p[maxn];
    int n;
     
    void solve(){
    	scanf("%d",&n);
    	for(int i=0;i<n;i++)	scanf("%d %d",&p[i].x,&p[i].y);
    	if(n%2)	printf("NO\n");
    	else{
    		int flag=1;
    		for(int i=0;i<n;i++){
    			point p1=p[i%n],p2=p[(i+1)%n];
    			point p3=p[(i+n/2)%n],p4=p[(i+n/2+1)%n];
    			if((p1-p2)+(p3-p4)!=vctor(0,0)){
    				flag=0;break;
    			}
    		}
    		printf("%s\n",flag?"YES":"NO");
    	}
    }
    int main(){
    	solve();
    	return 0;
    }