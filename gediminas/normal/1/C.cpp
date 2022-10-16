#include <bits/stdc++.h>

using namespace std;

struct point{
    long double x, y;
    point operator-(const point&o)const{
        return {x-o.x,y-o.y};
    }
    long double distance(const point&o)const{
        return sqrt((o.x-x)*(o.x-x)+(o.y-y)*(o.y-y));
    }
    long double angle(const point&o)const{
        return atan2(o.y-y, o.x-x);
    }
};

const long double pi = 3.14159265359l;

long double angle(const point&a, const point&b, const point&c){
    long double kamp = b.angle(c)-b.angle(a);
    if(kamp<0)
        kamp+=2*pi;
    if(kamp>pi)
        kamp=2*pi-kamp;
    return kamp;
}

bool lygu(long double a, long double b){
    return abs(a-b)<=0.0001;
}

int main () {
	point a,b,c;
	cout << fixed << setprecision(8);
	while(cin >> a.x >> a.y){
    	cin >> b.x >> b.y;
    	cin >> c.x >> c.y;
    	
    	/*cout << a.distance(b) << endl;
    	cout << a.distance(c) << endl;
    	cout << b.distance(c) << endl;*/
    	
    	for(int n=3;n<=100;n++){
    	    for(int k = 1;k<=n-2;k++){
    	        for(int l = 1;l<=n-2 and l+k<=n-1;l++){
        	        if(lygu(angle(a,b,c), pi*k/2*(1-(n-2)*1.0l/n))
        	        and lygu(angle(b,c,a), pi*l/2*(1-(n-2)*1.0l/n))
        	         and lygu(angle(c,a,b), pi*(n-l-k)/2*(1-(n-2)*1.0l/n))){
        	             long double z = a.distance(c);
        	            // cout << n << " " << z << " " << (z/(2*sin(angle(a,b,c)))) << endl;
        	            cout << n*(z/(2*sin(angle(a,b,c))))*(z/(2*sin(angle(a,b,c))))/2*sin(2*pi/n) << endl;
        	            n=100;
        	            k=100;
        	            break;
        	        }
    	        }
    	    }
    	}
        
	}
	return 0;
}