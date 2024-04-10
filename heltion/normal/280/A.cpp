#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
const double eps = 1e-8;
struct Point{
    double x, y;
    Point(double x, double y): x(x), y(y){}
    Point operator + (const Point &point) const{
        return (Point){x + point.x, y + point.y};
    }
    Point operator += (const Point &point){
        return (Point){x += point.x, y += point.y};
    }
    Point operator - (const Point &point) const{
        return (Point){x - point.x, y - point.y};
    }
    Point operator * (const double &k) const{
        return (Point){k * x, k * y};
    }
    double operator * (const Point &point) const{
        return x * point.y - y * point.x;
    }
    void rotate(double angle){
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x, y = new_y;
    }
};

struct Segment{
    Point point1, point2;
    Segment(Point point1, Point point2): point1(point1), point2(point2){}
    friend bool intersection(const Segment &segment1, const Segment &segment2, Point &point){
        Point vector1 = segment1.point2 - segment1.point1;
        Point vector2 = segment2.point2 - segment2.point1;
        double cross = vector1 * vector2;
        if(fabs(cross) < eps) return false;
        double t = ((segment2.point1 - segment1.point1) * vector2) / cross;
        double u = ((segment2.point1 - segment1.point1) * vector1) / cross;
        if(t < -eps or t > 1 + eps or u < -eps or u > 1 + eps) return false;
        point = segment1.point1 + vector1 * t;
        return true;
    }  
};

struct Polygon{
    std::vector<Point> vertex;
    void add_point(double x, double y){
        vertex.push_back((Point){x, y});
    }
    void add_point(Point point){
        vertex.push_back(point);
    }
    Polygon operator = (const Polygon &polygon){
        for(Point point: polygon.vertex) vertex.push_back(point);
        return *this;
    }
    void rotate(double angle){
        for(Point &point: vertex) point.rotate(angle);
    }
    void anglesort(){
        Point center(0, 0);
        for(Point k: vertex) center += k;
        auto cmp = [&](const Point &point1, const Point &point2)-> bool{
            return atan2(point1.y - center.y, point1.x - center.x)
                < atan2(point2.y - center.y, point2.x - center.x);
        };
        std::sort(vertex.begin(), vertex.end(), cmp);
    }
    double area(){
        int n = vertex.size();
        double ret = 0;
        for(int i = 0; i < n; i += 1)
            ret += vertex[i] * vertex[(i + 1) % n];
        return fabs(ret / 2);
    }
    friend Polygon cap(const Polygon &polygon1, const Polygon &polygon2){
        Polygon polygon;
        int n1 = polygon1.vertex.size();
        int n2 = polygon2.vertex.size();
        Point point(0, 0);
        for(int i1 = 0; i1 < n1; i1 += 1)
            for(int i2 = 0; i2 < n2; i2 += 1)
                if(intersection(Segment(polygon1.vertex[i1], polygon1.vertex[(i1 + 1) % n1]),
                    Segment(polygon2.vertex[i2], polygon2.vertex[(i2 + 1) % n2]),
                    point))
                polygon.add_point(point);
        return polygon;
    }
};

int main(){
    double w, h, a;
    scanf("%lf %lf %lf", &w, &h, &a);
    if(fabs(a - 0) < eps or fabs(a - 180) < eps){
        printf("%lf", w * h);
        return 0;
    }
    Polygon rectangle, rectangle2;
    rectangle.add_point(w / 2, h / 2);
    rectangle.add_point(- w / 2, h / 2);
    rectangle.add_point(- w / 2, - h / 2);
    rectangle.add_point(w / 2, - h / 2);
    rectangle2 = rectangle;
    rectangle.rotate(a * acos(-1) / 180);
    Polygon polygon = cap(rectangle, rectangle2);
    polygon.anglesort();
    printf("%lf", polygon.area());
}