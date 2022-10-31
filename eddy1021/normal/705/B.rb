n = gets.to_i
a = gets.split.map(&:to_i)
sum = 0
a.each{ |x|
  sum += x - 1
  puts 2 - sum % 2
}