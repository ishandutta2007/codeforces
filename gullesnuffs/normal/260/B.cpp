#include <stdio.h>

using namespace std;

int occur[2016][13][32], days[13]={0, 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};

int main()
{
    char input[100005];
    scanf("%s", input);
    for(int i=0; input[i]; ++i){
        bool ok=1;
        for(int j=0; j < 10; ++j){
            if(!input[i+j])
                ok=0;
        }
        if(!ok)
            break;
        if(input[i+2] != '-')
            continue;
        if(input[i+5] != '-')
            continue;
        for(int j=0; j < 10; ++j){
            if(j == 2 || j == 5)
                continue;
            if(input[i+j] == '-')
                ok=0;
        }
        if(!ok)
            continue;
        int d=0, m=0, y=0;
        for(int j=0; j < 2; ++j)
            d=10*d+input[i+j]-'0';
        for(int j=3; j < 5; ++j)
            m=10*m+input[i+j]-'0';
        for(int j=6; j < 10; ++j)
            y=10*y+input[i+j]-'0';
        if(m <= 0 || m > 12)
            continue;
        if(y < 2013 || y > 2015)
            continue;
        if(d > days[m] || d <= 0)
            continue;
        ++occur[y][m][d];
    }
    int best=0;
    for(int y=2013; y <= 2015; ++y)
        for(int m=1; m <= 12; ++m)
            for(int d=1; d <= days[m]; ++d)
                if(occur[y][m][d] > best){
                    best=occur[y][m][d];
                }
    for(int y=2013; y <= 2015; ++y){
        for(int m=1; m <= 12; ++m)
            for(int d=1; d <= days[m]; ++d)
                if(occur[y][m][d] == best){
                    printf("%d%d-%d%d-%d", d/10, d%10, m/10, m%10, y);
                    return 0;
                }
    }
    return 0;
}