#include <stdio.h>
#include <complex>
#include <math.h>
#include <algorithm>
#include <map>
#define INF 1e9
#define eps 1e-7

using namespace std;

int chargeTime, shootTime;
double dis[1005], waitDis[1005];

int trenchN;
complex<int> trench[1005][2], A, B;
bool visited[1005];

int main()
{
    scanf("%d%d", &chargeTime, &shootTime);
    int Ax, Ay, Bx, By;
    scanf("%d%d%d%d", &Ax, &Ay, &Bx, &By);
    A=complex<int>(Ax, Ay);
    B=complex<int>(Bx, By);
    scanf("%d", &trenchN);
    for(int i=0; i < trenchN; ++i){
        int x, y;
        for(int j=0; j < 2; ++j){
            scanf("%d%d", &x, &y);
            trench[i][j]=complex<int>(x, y);
        }
        complex<int> dif=trench[i][1]-trench[i][0];
        if(real(dif) < 0 || imag(dif) < 0)
            swap(trench[i][0], trench[i][1]);
    }
    trench[trenchN][0]=complex<int>(Ax, Ay);
    trench[trenchN++][1]=complex<int>(Ax, Ay);
    trench[trenchN][0]=complex<int>(Bx, By);
    trench[trenchN++][1]=complex<int>(Bx, By);
    for(int i=0; i < trenchN; ++i){
        dis[i]=INF;
        visited[i]=0;
    }
    dis[trenchN-2]=0;
    waitDis[trenchN-2]=0;
    while(true){
        int pos=-1;
        for(int i=0; i < trenchN; ++i){
            if(dis[i] < INF-eps && !visited[i] && (pos == -1 || dis[i] < dis[pos]))
                pos=i;
        }
        if(pos == -1)
            break;
        visited[pos]=1;
        double d=waitDis[pos];
        for(int i=0; i < trenchN; ++i){
            if(visited[i])
                continue;
            double addDis=INF;
            for(int j=0; j < 2; ++j){
                complex<int> from;
                complex<int> *seg;
                for(int k=0; k < 2; ++k){
                    if(j == 0){
                        from=trench[pos][k];
                        seg=trench[i];
                    }
                    else{
                        from=trench[i][k];
                        seg=trench[pos];
                    }
                    addDis=min(addDis, sqrt(double(norm(from-seg[0]))));
                    addDis=min(addDis, sqrt(double(norm(from-seg[1]))));
                    if(real(from) > real(seg[0]) && real(from) < real(seg[1])){
                        addDis=min(addDis, double(abs(imag(from)-imag(seg[0]))));
                    }
                    if(imag(from) > imag(seg[0]) && imag(from) < imag(seg[1])){
                        addDis=min(addDis, double(abs(real(from)-real(seg[0]))));
                    }
                }
            }
            if(d+addDis+shootTime < dis[i] && addDis < chargeTime+eps){
                dis[i]=d+addDis+shootTime;
                waitDis[i]=d+chargeTime+shootTime;
            }
        }
    }
    if(dis[trenchN-1] > INF-eps){
        printf("-1");
    }
    else{
        printf("%lf", dis[trenchN-1]-shootTime);
    }
    return 0;
}