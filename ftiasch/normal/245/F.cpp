#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int t, m;

const int DAY[13] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char buffer[5000000 + 1]; 


int main() {
    scanf("%d%d", &t, &m);
    gets(buffer);
    queue <int> events;
    int sum = 0;
    while (gets(buffer)) {
        for (int i = 0; buffer[i]; ++ i) {
            if (!isdigit(buffer[i])) {
                buffer[i] = ' ';
            }
        }
        int year, month, day, hour, minute, second;
        sscanf(buffer, "%d%d%d%d%d%d", &year, &month, &day, &hour, &minute, &second);
        int time = 0;
        for (int i = 1; i < month; ++ i) {
            time += DAY[i];
        }
        time += day - 1;
        time *= 24;
        time += hour;
        time *= 60;
        time += minute;
        time *= 60;
        time += second;
        sum ++;
        events.push(time + t);
        while (!events.empty() && events.front() <= time) {
            sum --;
            events.pop();
        }
        if (sum >= m) {
            buffer[4] = buffer[7] = '-';
            buffer[13] = buffer[16] = ':';
            buffer[19] = '\0';
            printf("%s\n", buffer);
            return 0;
        }
    }
    puts("-1");
    return 0;
}