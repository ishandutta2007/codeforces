#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 999999999
using namespace std;

int main()
{
    long long m, R;
    scanf("%I64d%I64d", &m, &R);
    double sum=0;
    sum += 2*R*m;
    sum += (2+sqrt(2.0))*R*(2*m-2);
    sum += 2*sqrt(2.0)*R*(m-1)*(m-2);
    sum += 2*R*(((m-1)*(m-2)*m)/3);
    printf("%.7lf\n", sum/double(m*m));
    return 0;
}