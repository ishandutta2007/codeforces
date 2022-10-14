# Codeforces Round #138
# Problem A -- Parallelepiped
a, b, c = gets.split.map(&:to_i)
1.upto a do |i|
    j = a / i
    k = b / i
    puts (i + j + k) * 4 if i * j == a and i * k == b and j * k == c 
end