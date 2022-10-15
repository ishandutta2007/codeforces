var a = [];

for (var i = 0; i < 6; i++) {
    a[i] = readline();
}

var good = [
    [3, 3, -1, 4, 4, -1, 3, 3],    
    [3, 3, -1, 4, 4, -1, 3, 3],    
    [2, 2, -1, 3, 3, -1, 2, 2],    
    [2, 2, -1, 3, 3, -1, 2, 2],    
    [1, 1, -1, 2, 2, -1, 1, 1],
    [1, 1, -1, 2, 2, -1, 1, 1],    
];

bx = -1; by = -1;
for (var i = 0; i < 6; i++) {
    for (var j = 0; j < 8; j++) {
        if (a[i][j] != '.') {
            continue;
        }
        if (bx < 0 || good[i][j] > good[bx][by]) {
            bx = i; by = j;
        }
    }
}

var b = []

for (var i = 0; i < 6; i++) {
    b[i] = "";
    for (var j = 0; j < 8; j++) {
        if (i == bx && j == by) {
            b[i] += 'P';
        } else {
            b[i] += a[i][j];
        }
    }
    print(b[i]);
}