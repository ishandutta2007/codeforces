n = gets.to_i
a = gets.split.map(&:to_i)
gets.to_i.times do
    x, y = gets.split.map(&:to_i)
    x -= 1
    a[x - 1] += y - 1 if x - 1 >= 0
    a[x + 1] += a[x] - y if x + 1 < n
    a[x] = 0
end
puts a