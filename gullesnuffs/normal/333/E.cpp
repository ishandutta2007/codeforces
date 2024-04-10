#include <stdio.h>
#include <cmath>
#include <algorithm>
#define eps 0.0000001F

using namespace std;

int n;
int p[3005][2];
pair<double, int> angle[3005][3005];
double dis[3005][3005];
double pi=3.14159265358F;

bool differ(double a, double b){
    if(a > b)
        return differ(b, a);
    if(b-a < pi/3.0+eps)
        return 0;
    if(a-b+2*pi < pi/3.0+eps)
        return 0;
    return 1;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i)
        scanf("%d%d", p[i], p[i]+1);
    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){
            double dy=(double) (p[j][0]-p[i][0]), dx=(double) (p[j][1]-p[i][1]);
            dis[i][j]=sqrt(dy*dy+dx*dx);
            if(j == i){
                angle[i][j]=make_pair(0, j);
                continue;
            }
            angle[i][j]=make_pair(atan2(dy, dx), j);
        }
        sort(angle[i], angle[i]+n);
    }
    double Max=100000, Min=0;
    while(Max-Min > 0.0000001){
        double test=(Max+Min)/2;
        bool ok=0;
        for(int i=0; i < n && !ok; ++i){
            int first, prev;
            bool any=0;
            for(int j=0; j < n; ++j){
                int k=angle[i][j].second;
                if(dis[i][k] < test)
                    continue;
                if(any){
                    if(differ(angle[i][j].first, angle[i][prev].first))
                        ok=1;
                    if(differ(angle[i][j].first, angle[i][first].first))
                        ok=1;
                }
                else
                    first=j;
                prev=j;
                any=1;
            }
        }
        if(ok)
            Min=test;
        else
            Max=test;
    }
    printf("%.7lf\n", (Max+Min)/4.0);
    return 0;
}