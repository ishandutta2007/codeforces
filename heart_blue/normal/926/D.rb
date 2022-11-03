#!/usr/bin/ruby
 
val = Array.new(6)
for i in 0..5
    val[i] = gets
end
a = Array[
Array[3,3,0,4,4,0,3,3],
Array[3,3,0,4,4,0,3,3],
Array[2,2,0,3,3,0,2,2],
Array[2,2,0,3,3,0,2,2],
Array[1,1,0,2,2,0,1,1],
Array[1,1,0,2,2,0,1,1]
]
str = 'P'
key = str[0]
maxv = 0
x = 0
y = 0
for i in 0..5
    for j in 0..7
        if val[i][j] == '.' and a[i][j] > maxv
            maxv = a[i][j]
            x = i
            y = j
        end
    end
end
y = y.to_i
val[x][y] = 'P'
for i in 0..5
    puts val[i]
end