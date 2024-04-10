#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

long long ReadLL() {
    long long answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

double Area(double x, double h) {
    return x * x / h * 0.5;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    double h;
    scanf("%d%lf", &n, &h);
    double piece = h * 0.5 / n, before = 0;
    for (int i = 1; i < n; i++) {
        double left = before, right = h;
        for (int step = 1; step <= 120; step++) {
            double middle = (left + right) * 0.5;
            double area = Area(middle, h);
            if (area < piece * i)
                left = middle;
            else
                right = middle;
        }
        printf("%.12f ", left);
        before = left;
    }
    return 0;
}