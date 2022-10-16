    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
     
    double tricky(double a, double b){
        //printf("%10.10lf %10.10lf\n", a, b);
        if(a<b) swap(a,b);
        while(a>b+100000) a-=b;
        return (abs(a-b)>100000)? tricky(a,b) : b;
    }
     
    double bigcos(double a, double b, double c){
        double g;
        g=((b*b)+(c*c)-(a*a));
        g/=(2*b*c);
        return g;
    }
     
    double disto(double x1, double y1, double x2, double y2){
        double g=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
        g=sqrt(g);
        return g;
    }
     
     
    int main(){
        double xa, ya, xb, yb, xc, yc; scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
        double A=disto(xb, yb, xc, yc);
        double B=disto(xa, ya, xc, yc);
        double C=disto(xb, yb, xa, ya);
        //cout<< A<< " "<< B<< " "<< C<< endl;
        double ta=bigcos(A,B,C);
        double tb=bigcos(B,A,C);
        double tc=bigcos(C,B,A);
        double R=(A/(2*sqrt(1-(ta*ta)))+B/(2*sqrt(1-(tb*tb)))+C/(2*sqrt(1-(tc*tc))))/3;
        //cout<< "r "<< R<< endl;
        //cout<< ta<< " "<< tb<< " "<< tc<< endl;
        ta=1000000000*acos(ta);
        tb=1000000000*acos(tb);
        tc=1000000000*acos(tc);
        //cout<< ta<< " "<< tb<< " "<< tc<< endl;
        double f=(ta+tb+tc)/(tricky(ta,tricky(tb,tc)));
        double g=ceil(f), h=floor(f);
        ((g-f)<(f-h))? f=g : f=h;
        //cout<< f<< endl;
        g=6.283185307;
        f=f*R*R*sin(g/f)/2;
        printf("%.8lf\n", f);
    }