#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
const long double eps = 1e-18;
int sign(const long double &value){
    if(abs(value) <= eps){
        return 0;
    }
    if(value < 0){
        return -1;
    }
    else{
        return 1;
    }
}
const long double pi = acos(-1);
struct Point{
    bool add2pi = 0;
    long double x,y;
    Point(){}
    Point(long double x,long double y) : x(x), y(y) {}
    long double angle() const{
        if(x==0){
            if(y>0){
                return pi/2;
            }
            else{
                return 3*pi/2;
            }
            return 0;
        }
        long double theta = atan(abs(y/x));
        if(x<0){
            theta = pi - theta;
        }
        if(y<0){
            theta = 2*pi - theta;
        }
        return theta + 2*pi*add2pi;
    }
    long double dist(){
        return sqrtl(x*x + y*y);
    }
};
istream& operator>>(istream &in, Point &x){
    in>>x.x>>x.y;
    return in;
}
ostream& operator<<(ostream& out, const Point &x){
    out<<x.x<<" "<<x.y<<" ";
    return out;
}
struct Line{
    bool v;
    long double m,c;
    Point x,y;
    //y = mx + c
    //y - mx - c = 0
    Line(const Point &_x, const Point &_y) : x(_x), y(_y){
        if(abs(x.x - y.x) <= eps){
            v = 1;
            c = x.x;
            return;
        }
        else{
            v = 0;
        }
        m  = (x.y - y.y)/(x.x - y.x);
        c = x.y - m*x.x;
    }
    int getside(const Point &p){
        if(v){
            if(sign(c)==1){
                return p.x>=c;
            }
            else{
                return p.x<=c;
            }
        }
        int sn1 = sign(-c);
        int sn2 = sign(p.y - m*p.x - c);
        if(sn2==0){
            return 0;
        }
        if((sn2<0) ^ (sn1<0)){
            return 1;
        }
        else{
            return -1;
        }
    }
    Point intersect(long double theta){
        if(v){
            return Point(c, tan(theta)*c);
        }
        while(theta > pi){
            theta-=pi;
        }
        if(abs(theta - pi/2) < eps){
            return Point(0,c);
        }
        if(abs(tan(theta) - m) <= eps){
            if(x.dist() < y.dist()){
                return x;
            }
            else{
                return y;
            }
        }
        return Point(c/(tan(theta) - m), c*tan(theta)/(tan(theta) - m));
    }
    long double perpdistance(){
        if(v){
            return c;
        }
        if(abs(m) < eps){
            return c;
        }
        return intersect(atan(1/m)).dist();
    }
};
long double area(const vector<Point>& points){
    if(points.size() < 3){
        return 0;
    }
    int n = points.size();
    long double ans = points[n-1].x * points[0].y - points[0].x * points[n-1].y;
    for(int i=0;i+1<n;i++){
        ans+=points[i].x * points[i+1].y;
    }
    for(int i=1;i<n;i++){
        ans-=points[i].x * points[i-1].y;
    }
    return abs(ans)/2;
}
struct Polygon{
    vector<Point> upper;
    vector<Point> lower;
    vector<Point> points;
    Point l,r;
    long double Distance;
    void build(vector<Point> _points){
        points = _points;
        assert(points.size() >= 3);
        int n = points.size();
        sort(points.begin(), points.end(), [&](const Point &x, const Point &y){
        return x.angle() < y.angle() && abs(x.angle() - y.angle()) > eps;
        });
        l = points[0];
        r = points[n-1];
        if(r.angle() - l.angle() > pi){
            for(int i=0;i<n;i++){
                if(points[i].angle()<pi){
                    points[i].add2pi = 1;
                }
            }
            sort(points.begin(), points.end(), [&](const Point &x, const Point &y){
                return x.angle() < y.angle() && abs(x.angle() - y.angle()) > eps;
            });
            l = points[0];
            r = points[n-1];
        }
        Line mid(l,r);
        upper.push_back(l);
        lower.push_back(l);
        for(int i=1;i<n-1;i++){
            if(mid.getside(points[i]) == 1){
                upper.push_back(points[i]);
            }
            else{
                lower.push_back(points[i]);
            }
        }
        upper.push_back(r);
        lower.push_back(r);
        Distance = 1e18;
        for(int i=1;i<lower.size();i++){
            Distance = min(Distance, Line(lower[i], lower[i-1]).perpdistance());
        }
    }
    bool blocking(const Point &p){
        long double theta = p.angle();
        if(r.angle() > 2*pi){
            if(theta < pi) theta += 2*pi;
        }
        if(theta < l.angle() || theta > r.angle()){
            return true;
        }
        int mn = 0, mx = lower.size() - 1;
        while(mn < mx){
            int mid = mn + mx + 1;
            mid>>=1;
            if(lower[mid].angle() < theta){
                mn = mid;
            }
            else{
                mx = mid - 1;
            }
        }
        if(Line(lower[mn], lower[mn + 1]).getside(p)==1){
            return false;
        }
        else{
            return true;
        }
    }
    int binsearch(const vector<Point>& seq, long double theta){ //returns index of first point at angle greater than theta
        int mn = 0;
        int mx = seq.size() - 1;
        if(seq[mx].angle() < theta){
            return seq.size();
        }
        while(mn < mx){
            int mid = mn + mx;
            mid>>=1;
            if(seq[mid].angle() < theta){
                mn = mid + 1;
            }
            else{
                mx = mid;
            }
        }
        return mn;
    }
    long double areabetween(long double theta1, long double theta2){
        if(abs(theta1 - theta2) <=eps){
            return 0;
        }
        if(r.angle() > 2*pi){
            if(theta1 < pi) theta1 += 2*pi;
            if(theta2 < pi) theta2 += 2*pi;
        }
        if(theta2 < theta1){
            //assert(false && "nonsense");
            swap(theta1, theta2);
        }
        vector<Point> finalpoints;
        int llow = binsearch(lower, theta1);
        int lup = binsearch(upper, theta1);
        int rlow = binsearch(lower, theta2);
        int rup = binsearch(upper, theta2);
        //cout<<llow<<" "<<rlow<<" "<<lup<<" "<<rup<<"\n";
        //cout+lower+upper;
        if(llow!=0){
            finalpoints.pb(Line(lower[llow], lower[llow-1]).intersect(theta1));
        }
        for(int i=llow;i<rlow;i++){
            finalpoints.pb(lower[i]);
        }
        if(rlow!=lower.size()){
            finalpoints.pb(Line(lower[rlow], lower[rlow-1]).intersect(theta2));
        }
        if(rup!=upper.size()){
            finalpoints.pb(Line(upper[rup], upper[rup-1]).intersect(theta2));
        }
        for(int i=rup-1;i>=lup;--i){
            finalpoints.pb(upper[i]);
        }
        if(lup!=0){
            finalpoints.pb(Line(upper[lup], upper[lup-1]).intersect(theta1));
        }
        finalpoints.resize(unique(finalpoints.begin(), finalpoints.end(), [&](const Point &x, const Point &y){
            return abs(x.x-y.x) <= eps && abs(x.y-y.y) <=eps; 
        }) - finalpoints.begin());
        //cout+finalpoints;
        return area(finalpoints);
    }    
    long double angledist(long double theta){
        if(r.add2pi && theta < pi) theta+=2*pi;
        if(theta < l.angle() || theta>r.angle()){
            return 1e12;
        }
        int llow = binsearch(lower, theta);
        if(llow==0){
            ++llow;
        }
        return Line(lower[llow], lower[llow-1]).intersect(theta).dist();
    }
};
void solve(){
    int n;
    cin>>n;
    vector<Polygon> warehouses(n);
    for(int i=0;i<n;i++){
        auto &warehouse = warehouses[i];
        int size;
        cin>>size;
        vector<Point> warehousepoints(size);
        cin>>warehousepoints;
        warehouse.build(warehousepoints);
    }
    struct Event{
        long double theta;
        int idx;
        bool add;
        Event(){}
        Event(long double theta, int idx, bool add) : theta(theta), idx(idx), add(add) {}
        bool operator<(const Event &E){
            return theta < E.theta;
        }
    };
    vector<Event> events;
    for(int i=0;i<n;i++){
        const auto &warehouse = warehouses[i];
        if(warehouse.r.add2pi){
            events.pb({0,i,1});
            events.pb({warehouse.r.angle() - 2*pi, i, 0});
            events.pb({warehouse.l.angle(), i, 1});
            events.pb({2*pi, i, 0});
        }
        else{
            events.pb({warehouse.l.angle(), i, 1});
            events.pb({warehouse.r.angle(), i, 0});
        }
    }
    sort(events.begin(), events.end());
    /*for(const auto &E : events){
        //cout<<E.theta<<" "<<E.idx<<" "<<E.add<<"\n";
    }*/
    //cout<<"\n";
    long double ans = 0;
    long double currtheta = 0;
    auto cmp = [&](int x,int y){
        return warehouses[x].angledist(currtheta) < warehouses[y].angledist(currtheta);
    };
    multiset<int, decltype(cmp)> pq(cmp);
    //set<int> pq;
    //cout<<warehouses[0].angledist(0)<<" "<<warehouses[1].angledist(0)<<"\n";
    for(int i=1;i<events.size();i++){
        if(!events[i-1].add){
            pq.erase(events[i-1].idx);
        }
        long double theta1 = events[i-1].theta;
        long double theta2 = events[i].theta;
        currtheta = (theta1 + theta2)/2;
        if(events[i-1].add){
            pq.insert(events[i-1].idx);
        }
        if(pq.empty()){
            //cout<<"-1\n";
            //cout<<"-1\n\n";
            continue;
        }
        /*for(const auto &x : pq){
            cout<<x<<" ";
        }*/
        //cout<<"\n";
        int idx = (*pq.begin());
        //cout<<idx<<" "<<theta1<<" "<<theta2<<"\n\n";
        ans+=warehouses[idx].areabetween(theta1, theta2);
    }
    cout<<ans<<"\n";
}
void play(){
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    //play();
}
/*
0 0 1
0 1 1
0 1 0
0 4 1
0.165149 4 0
1.5708 0 0
1.5708 3 1
3.14159 2 1
3.14159 3 0
4.54724 5 1
4.71239 1 1
4.71239 2 0
4.87754 5 0
6.03821 4 1
6.28319 1 0
6.28319 4 0

0 0 0
0 0 0
0 0 0
0 0 0.165149
0 0.165149 1.5708
3 1.5708 3.14159
2 3.14159 3.14159
2 3.14159 4.54724
2 4.54724 4.71239
1 4.71239 4.71239
1 4.71239 4.87754
1 4.87754 6.03821
1 6.03821 6.28319
4 6.28319 6.28319
48.000000000
*/